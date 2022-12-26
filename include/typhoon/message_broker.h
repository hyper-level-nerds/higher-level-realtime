/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/TYPHOONCPP/tphn
https://www.tphncpp.com

Copyright(c) 2017 John Wellbelove

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#ifndef TYPHOON_MESSAGE_BROKER_INCLUDED
#define TYPHOON_MESSAGE_BROKER_INCLUDED

#include "platform.h"
#include "nullptr.h"
#include "message_types.h"
#include "message.h"
#include "message_router.h"
#include "span.h"

#include <stdint.h>

namespace tphn
{
  //***************************************************************************
  /// Message broker
  //***************************************************************************
  class message_broker : public tphn::imessage_router
  {
  private:

    //*******************************************
    class subscription_node
    {
      friend class message_broker;

    protected:

      //*******************************
      subscription_node()
        : p_next(TYPHOON_NULLPTR)
      {
      }

      //*******************************
      void set_next(subscription_node* sub)
      {
        p_next = sub;
      }

      //*******************************
      subscription_node* get_next() const
      {
        return p_next;
      }

      //*******************************
      void terminate()
      {
        set_next(TYPHOON_NULLPTR);
      }

      //*******************************
      void append(subscription_node* sub)
      {
        if (sub != TYPHOON_NULLPTR)
        {
          sub->set_next(get_next());
        }
        set_next(sub);
      }

      subscription_node* p_next;
    };

  public:

    typedef tphn::span<const tphn::message_id_t> message_id_span_t;

    //*******************************************
    class subscription : public subscription_node
    {
    public:

      friend class message_broker;

      //*******************************
      subscription(tphn::imessage_router& router_)
        : p_router(&router_)
      {
      }

    private:

      //*******************************
      virtual message_id_span_t message_id_list() const = 0;

      //*******************************
      tphn::imessage_router* get_router() const
      {
        return p_router;
      }

      //*******************************
      subscription* next_subscription() const
      {
        return static_cast<subscription*>(get_next());
      }

      tphn::imessage_router* const p_router;
    };

    using tphn::imessage_router::receive;
    
    //*******************************************
    /// Constructor.
    //*******************************************
    message_broker()
      : imessage_router(tphn::imessage_router::MESSAGE_BROKER)
      , head()
    {
    }

    //*******************************************
    /// Constructor.
    //*******************************************
    message_broker(tphn::imessage_router& successor_)
      : imessage_router(tphn::imessage_router::MESSAGE_BROKER, successor_)
      , head()
    {
    }

    //*******************************************
    /// Constructor.
    //*******************************************
    message_broker(tphn::message_router_id_t id_)
      : imessage_router(id_)
      , head()
    {
      TYPHOON_ASSERT((id_ <= tphn::imessage_router::MAX_MESSAGE_ROUTER) || (id_ == tphn::imessage_router::MESSAGE_BROKER), TYPHOON_ERROR(tphn::message_router_illegal_id));
    }

    //*******************************************
    /// Constructor.
    //*******************************************
    message_broker(tphn::message_router_id_t id_, tphn::imessage_router& successor_)
      : imessage_router(id_, successor_)
      , head()
    {
      TYPHOON_ASSERT((id_ <= tphn::imessage_router::MAX_MESSAGE_ROUTER) || (id_ == tphn::imessage_router::MESSAGE_BROKER), TYPHOON_ERROR(tphn::message_router_illegal_id));
    }

    //*******************************************
    /// Subscribe to the broker.
    //*******************************************
    void subscribe(tphn::message_broker::subscription& new_sub)
    {
      initialise_insertion_point(new_sub.get_router(), &new_sub);
    }

    //*******************************************
    void unsubscribe(tphn::imessage_router& router)
    {
      initialise_insertion_point(&router, TYPHOON_NULLPTR);
    }

    //*******************************************
    virtual void receive(const tphn::imessage& msg) TYPHOON_OVERRIDE
    {
      const tphn::message_id_t id = msg.get_message_id();

      if (!empty())
      {
        // Scan the subscription lists.
        subscription* sub = static_cast<subscription*>(head.get_next());

        while (sub != TYPHOON_NULLPTR)
        {
          message_id_span_t message_ids = sub->message_id_list();

          message_id_span_t::iterator itr = tphn::find(message_ids.begin(), message_ids.end(), id);

          if (itr != message_ids.end())
          {
            sub->get_router()->receive(msg);
          }

          sub = sub->next_subscription();
        }
      }

      // Always pass the message on to the successor.
      if (has_successor())
      {
        tphn::imessage_router& successor = get_successor();

        successor.receive(msg);
      }
    }

    //*******************************************
    virtual void receive(tphn::shared_message shared_msg) TYPHOON_OVERRIDE
    {
      const tphn::message_id_t id = shared_msg.get_message().get_message_id();

      if (!empty())
      {
        // Scan the subscription lists.
        subscription* sub = static_cast<subscription*>(head.get_next());

        while (sub != TYPHOON_NULLPTR)
        {
          message_id_span_t message_ids = sub->message_id_list();

          message_id_span_t::iterator itr = tphn::find(message_ids.begin(), message_ids.end(), id);

          if (itr != message_ids.end())
          {
            sub->get_router()->receive(shared_msg);
          }

          sub = sub->next_subscription();
        }
      }

      // Always pass the message on to a successor.
      if (has_successor())
      {
        get_successor().receive(shared_msg);
      }
    }

    using imessage_router::accepts;

    //*******************************************
    /// Message brokers accept all messages.
    //*******************************************
    virtual bool accepts(tphn::message_id_t) const TYPHOON_OVERRIDE
    {
      return true;
    }

    //*******************************************
    void clear()
    {
      head.terminate();
    }

    //********************************************
    TYPHOON_DEPRECATED virtual bool is_null_router() const TYPHOON_OVERRIDE
    {
      return false;
    }

    //********************************************
    virtual bool is_producer() const TYPHOON_OVERRIDE
    {
      return true;
    }

    //********************************************
    virtual bool is_consumer() const TYPHOON_OVERRIDE
    {
      return true;
    }

    //********************************************
    bool empty() const
    {
      return head.get_next() == TYPHOON_NULLPTR;
    }

  private:

    //*******************************************
    void initialise_insertion_point(const tphn::imessage_router* p_router, tphn::message_broker::subscription* p_new_sub)
    {
      const tphn::imessage_router* p_target_router = p_router;

      subscription_node* p_sub          = head.get_next();
      subscription_node* p_sub_previous = &head;

      while (p_sub != TYPHOON_NULLPTR)
      {
        // Do we already have a subscription for the router?
        if (static_cast<subscription*>(p_sub)->get_router() == p_target_router)
        {
          // Then unlink it.
          p_sub_previous->set_next(p_sub->get_next()); // Jump over the subscription.
          p_sub->terminate();                          // Terminate the unlinked subscription.

          // We're done now.
          break;
        }

        // Move on up the list.
        p_sub = p_sub->get_next();
        p_sub_previous = p_sub_previous->get_next();
      }

      if (p_new_sub != TYPHOON_NULLPTR)
      {
        // Link in the new subscription.
        p_sub_previous->append(p_new_sub);
      }
    }

    subscription_node head;
  };
}

#endif
