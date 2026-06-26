#include "Plugin.h"
#include "LogSetup.h"

#include "GameEventHandler.h"
#include "Util.h"

extern "C" DLLEXPORT bool SKSEPlugin_Load(const SKSE::LoadInterface *skse) {
    LogSetup::initializeLogging();

    INFO("'{}' by '{}' / Skyrim: '{}'", Plugin::Name, Plugin::Author, Plugin::VersionString, REL::Module::get().version().string());
    Init(skse, false);

    this_plugin::GameEventHandler::getInstance().onLoad();
    INFO("{} loaded.", Plugin::Name);
    return true;
}