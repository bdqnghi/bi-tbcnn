/*

 Copyright (c) 2013, SMB Phone Inc.
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 The views and conclusions contained in the software and documentation are those
 of the authors and should not be interpreted as representing official policies,
 either expressed or implied, of the FreeBSD Project.

 */

#include <openpeer/stack/internal/stack_Stack.h>
#include <openpeer/stack/message/bootstrapped-finder/MessageFactoryBootstrappedFinder.h>
#include <openpeer/stack/message/bootstrapper/MessageFactoryBootstrapper.h>
#include <openpeer/stack/message/certificates/MessageFactoryCertificates.h>
#include <openpeer/stack/message/identity/MessageFactoryIdentity.h>
#include <openpeer/stack/message/identity-lookup/MessageFactoryIdentityLookup.h>
#include <openpeer/stack/message/identity-lockbox/MessageFactoryIdentityLockbox.h>
#include <openpeer/stack/message/namespace-grant/MessageFactoryNamespaceGrant.h>
#include <openpeer/stack/message/rolodex/MessageFactoryRolodex.h>
#include <openpeer/stack/message/peer/MessageFactoryPeer.h>
#include <openpeer/stack/message/peer-common/MessageFactoryPeerCommon.h>
#include <openpeer/stack/message/peer-finder/MessageFactoryPeerFinder.h>
#include <openpeer/stack/message/peer-salt/MessageFactoryPeerSalt.h>
#include <openpeer/stack/message/peer-to-peer/MessageFactoryPeerToPeer.h>

#include <openpeer/stack/internal/stack_Settings.h>

#include <openpeer/stack/ISettings.h>

#include <openpeer/services/IHelper.h>
#include <openpeer/services/IMessageQueueManager.h>

#include <zsLib/Log.h>
#include <zsLib/XML.h>
#include <zsLib/helpers.h>
#include <zsLib/Stringize.h>


#define OPENPEER_STACK_STACK_THREAD_NAME          "org.openpeer.stack.stackThread"
#define OPENPEER_STACK_KEY_GENERATION_THREAD_NAME "org.openpeer.stack.keyGenerationThread"

namespace openpeer { namespace stack { ZS_DECLARE_SUBSYSTEM(openpeer_stack) } }

namespace openpeer
{
  namespace stack
  {
    namespace internal
    {
      using services::IHelper;

      using message::bootstrapped_finder::MessageFactoryBootstrappedFinder;
      using message::bootstrapper::MessageFactoryBootstrapper;
      using message::certificates::MessageFactoryCertificates;
      using message::identity::MessageFactoryIdentity;
      using message::identity_lookup::MessageFactoryIdentityLookup;
      using message::identity_lockbox::MessageFactoryIdentityLockbox;
      using message::namespace_grant::MessageFactoryNamespaceGrant;
      using message::rolodex::MessageFactoryRolodex;
      using message::peer::MessageFactoryPeer;
      using message::peer_common::MessageFactoryPeerCommon;
      using message::peer_finder::MessageFactoryPeerFinder;
      using message::peer_salt::MessageFactoryPeerSalt;
      using message::peer_to_peer::MessageFactoryPeerToPeer;

      //-----------------------------------------------------------------------
      //-----------------------------------------------------------------------
      //-----------------------------------------------------------------------
      //-----------------------------------------------------------------------
      #pragma mark
      #pragma mark IStackForInternal
      #pragma mark

      //-----------------------------------------------------------------------
      AgentInfo IStackForInternal::agentInfo()
      {
        AgentInfo info;
        StackPtr singleton = Stack::singleton();
        if (!singleton) return info;
        singleton->getAgentInfo(info);
        return info;
      }

      //-----------------------------------------------------------------------
      IMessageQueuePtr IStackForInternal::queueDelegate()
      {
        StackPtr singleton = Stack::singleton();
        if (!singleton) return IMessageQueuePtr();
        return singleton->queueDelegate();
      }

      //-----------------------------------------------------------------------
      IMessageQueuePtr IStackForInternal::queueStack()
      {
        return IStack::getStackQueue();
      }

      //-----------------------------------------------------------------------
      IMessageQueuePtr IStackForInternal::queueServices()
      {
        return IStack::getServicesQueue();
      }

      //-----------------------------------------------------------------------
      IMessageQueuePtr IStackForInternal::queueKeyGeneration()
      {
        return IStack::getKeyGenerationQueue();
      }

      //-----------------------------------------------------------------------
      void IStackForInternal::logInstanceInformation()
      {
        StackPtr singleton = Stack::singleton();
        if (!singleton) return;
        singleton->logInstanceInformation();
      }

      //-----------------------------------------------------------------------
      //-----------------------------------------------------------------------
      //-----------------------------------------------------------------------
      //-----------------------------------------------------------------------
      #pragma mark
      #pragma mark Stack
      #pragma mark

      //-----------------------------------------------------------------------
      Stack::Stack() :
        mID(zsLib::createPUID())
      {
        ZS_LOG_BASIC(log("created"))

        MessageFactoryBootstrappedFinder::singleton();
        MessageFactoryBootstrapper::singleton();
        MessageFactoryCertificates::singleton();
        MessageFactoryIdentity::singleton();
        MessageFactoryIdentityLookup::singleton();
        MessageFactoryIdentityLockbox::singleton();
        MessageFactoryNamespaceGrant::singleton();
        MessageFactoryRolodex::singleton();
        MessageFactoryPeer::singleton();
        MessageFactoryPeerCommon::singleton();
        MessageFactoryPeerFinder::singleton();
        MessageFactoryPeerSalt::singleton();
        MessageFactoryPeerToPeer::singleton();
      }

      //-----------------------------------------------------------------------
      Stack::~Stack()
      {
        mThisWeak.reset();
        ZS_LOG_BASIC(log("destroyed"))
      }

      //-----------------------------------------------------------------------
      StackPtr Stack::convert(IStackPtr stack)
      {
        return dynamic_pointer_cast<Stack>(stack);
      }

      //-----------------------------------------------------------------------
      StackPtr Stack::create()
      {
        StackPtr pThis(new Stack());
        pThis->mThisWeak = pThis;
        return pThis;
      }

      //-----------------------------------------------------------------------
      //-----------------------------------------------------------------------
      //-----------------------------------------------------------------------
      //-----------------------------------------------------------------------
      #pragma mark
      #pragma mark Stack => IStack
      #pragma mark

      //-----------------------------------------------------------------------
      StackPtr Stack::singleton()
      {
        static SingletonLazySharedPtr<Stack> singleton(create());
        StackPtr result = singleton.singleton();
        if (!result) {
          ZS_LOG_WARNING(Detail, slog("singleton gone"))
        }
        return singleton.singleton();
      }

      //-----------------------------------------------------------------------
      void Stack::setup(
                        IMessageQueuePtr defaultDelegateMessageQueue,
                        IMessageQueuePtr stackMessageQueue,
                        IMessageQueuePtr servicesMessageQueue,
                        IMessageQueuePtr keyGenerationQueue
                        )
      {
        AutoRecursiveLock lock(mLock);

        IMessageQueueManager::registerMessageQueueThreadPriority(OPENPEER_STACK_STACK_THREAD_NAME, zsLib::threadPriorityFromString(services::ISettings::getString(OPENPEER_STACK_SETTING_STACK_STACK_THREAD_PRIORITY)));
        IMessageQueueManager::registerMessageQueueThreadPriority(OPENPEER_STACK_KEY_GENERATION_THREAD_NAME, zsLib::threadPriorityFromString(services::ISettings::getString(OPENPEER_STACK_SETTING_STACK_KEY_GENERATION_THREAD_PRIORITY)));

        if (defaultDelegateMessageQueue) {
          mDelegateQueue = defaultDelegateMessageQueue;
        }

        if (stackMessageQueue) {
          mStackQueue = stackMessageQueue;
        }

        if (servicesMessageQueue) {
          mServicesQueue = servicesMessageQueue;
        }
        if (keyGenerationQueue) {
          mKeyGenerationQueue = keyGenerationQueue;
        }

        ISettingsForStack::applyDefaultsIfNoDelegatePresent();

        verifySettingIsSet(OPENPEER_COMMON_SETTING_APPLICATION_NAME);
        verifySettingIsSet(OPENPEER_COMMON_SETTING_APPLICATION_IMAGE_URL);
        verifySettingIsSet(OPENPEER_COMMON_SETTING_APPLICATION_URL);
        verifySettingIsSet(OPENPEER_COMMON_SETTING_APPLICATION_AUTHORIZATION_ID);
        verifySettingIsSet(OPENPEER_COMMON_SETTING_USER_AGENT);
        verifySettingIsSet(OPENPEER_COMMON_SETTING_DEVICE_ID);
        verifySettingIsSet(OPENPEER_COMMON_SETTING_OS);
        verifySettingIsSet(OPENPEER_COMMON_SETTING_SYSTEM);
        verifySettingIsSet(OPENPEER_COMMON_SETTING_INSTANCE_ID);

        ZS_THROW_INVALID_ARGUMENT_IF(!mDelegateQueue)
      }

      //-----------------------------------------------------------------------
      //-----------------------------------------------------------------------
      //-----------------------------------------------------------------------
      //-----------------------------------------------------------------------
      #pragma mark
      #pragma mark Stack => IStackForInternal
      #pragma mark

      //-----------------------------------------------------------------------
      void Stack::getAgentInfo(AgentInfo &result) const
      {
        result.mUserAgent = services::ISettings::getString(OPENPEER_COMMON_SETTING_USER_AGENT);
        result.mName = services::ISettings::getString(OPENPEER_COMMON_SETTING_APPLICATION_NAME);
        result.mImageURL = services::ISettings::getString(OPENPEER_COMMON_SETTING_APPLICATION_IMAGE_URL);
        result.mAgentURL = services::ISettings::getString(OPENPEER_COMMON_SETTING_APPLICATION_URL);
      }

      //-----------------------------------------------------------------------
      IMessageQueuePtr Stack::queueDelegate() const
      {
        AutoRecursiveLock lock(mLock);
        if (!mDelegateQueue) {
          ZS_LOG_WARNING(Detail, log("default message queue was not registered thus could cause crash if any delegate passed into methods was not associated to a IMessageQueue via MessageQueueAssociator"))
        }
        return mDelegateQueue;
      }

      //-----------------------------------------------------------------------
      IMessageQueuePtr Stack::queueStack()
      {
        AutoRecursiveLock lock(mLock);
        if (!mStackQueue) mStackQueue = IMessageQueueManager::getMessageQueue(OPENPEER_STACK_STACK_THREAD_NAME);
        return mStackQueue;
      }

      //-----------------------------------------------------------------------
      IMessageQueuePtr Stack::queueServices()
      {
        AutoRecursiveLock lock(mLock);
        if (!mServicesQueue) mServicesQueue = IHelper::getServiceQueue();
        return mServicesQueue;
      }

      //-----------------------------------------------------------------------
      IMessageQueuePtr Stack::queueKeyGeneration()
      {
        AutoRecursiveLock lock(mLock);
        if (!mKeyGenerationQueue) {
          mKeyGenerationQueue = IMessageQueueManager::getMessageQueue(OPENPEER_STACK_KEY_GENERATION_THREAD_NAME);
        }
        return mKeyGenerationQueue;
      }

      //-----------------------------------------------------------------------
      void Stack::logInstanceInformation()
      {
        String deviceID = services::ISettings::getString(OPENPEER_COMMON_SETTING_DEVICE_ID);
        String instanceID = services::ISettings::getString(OPENPEER_COMMON_SETTING_INSTANCE_ID);
        String authorizedAppId = services::ISettings::getString(OPENPEER_COMMON_SETTING_APPLICATION_AUTHORIZATION_ID);

        AgentInfo agentInfo;
        getAgentInfo(agentInfo);

        ZS_LOG_FORCED(Informational, Basic, log("instance information") + ZS_PARAM("device id", deviceID) + ZS_PARAM("instance id", instanceID) + ZS_PARAM("authorized application id", authorizedAppId) + agentInfo.toDebug())
      }

      //-----------------------------------------------------------------------
      //-----------------------------------------------------------------------
      //-----------------------------------------------------------------------
      //-----------------------------------------------------------------------
      #pragma mark
      #pragma mark Stack => (internal)
      #pragma mark

      //-----------------------------------------------------------------------
      Log::Params Stack::log(const char *message) const
      {
        ElementPtr objectEl = Element::create("stack::Stack");
        IHelper::debugAppend(objectEl, "id", mID);
        return Log::Params(message, objectEl);
      }

      //-----------------------------------------------------------------------
      Log::Params Stack::slog(const char *message)
      {
        return Log::Params(message, "stack::Stack");
      }

      //-----------------------------------------------------------------------
      void Stack::verifySettingIsSet(const char *settingName)
      {
        ZS_THROW_INVALID_ARGUMENT_IF(!settingName)

        String result = services::ISettings::getString(settingName);
        if (!result.isEmpty()) return;

        ZS_LOG_WARNING(Basic, log("setting was not set") + ZS_PARAM("setting name", settingName))

        ZS_THROW_INVALID_USAGE(String("setting is missing a value: ") + settingName)
      }
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark IStack
    #pragma mark

    //-------------------------------------------------------------------------
    IStackPtr IStack::singleton()
    {
      return internal::Stack::singleton();
    }

    //-------------------------------------------------------------------------
    void IStack::setup(
                       IMessageQueuePtr defaultDelegateMessageQueue,
                       IMessageQueuePtr stackMessageQueue,
                       IMessageQueuePtr servicesQueue,
                       IMessageQueuePtr keyGenerationQueue
                       )
    {
      services::IHelper::setSocketThreadPriority();
      services::IHelper::setTimerThreadPriority();

      internal::StackPtr singleton = internal::Stack::singleton();
      ZS_THROW_INVALID_USAGE_IF(!singleton) // called during shutdown process?
      singleton->setup(defaultDelegateMessageQueue, stackMessageQueue, servicesQueue, keyGenerationQueue);
    }

    //-------------------------------------------------------------------------
    IMessageQueuePtr IStack::getStackQueue()
    {
      internal::StackPtr singleton = internal::Stack::singleton();
      if (!singleton) {
        return services::IMessageQueueManager::getMessageQueue(OPENPEER_STACK_STACK_THREAD_NAME);
      }
      return singleton->queueStack();
    }

    //-------------------------------------------------------------------------
    IMessageQueuePtr IStack::getServicesQueue()
    {
      internal::StackPtr singleton = internal::Stack::singleton();
      if (!singleton) {
        return services::IHelper::getServiceQueue();
      }
      return singleton->queueServices();
    }

    //-------------------------------------------------------------------------
    IMessageQueuePtr IStack::getKeyGenerationQueue()
    {
      internal::StackPtr singleton = internal::Stack::singleton();
      if (!singleton) {
        return services::IMessageQueueManager::getMessageQueue(OPENPEER_STACK_KEY_GENERATION_THREAD_NAME);
      }
      return singleton->queueKeyGeneration();
    }
  }
}
