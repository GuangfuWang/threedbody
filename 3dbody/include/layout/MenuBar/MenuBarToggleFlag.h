#ifndef INC_3DBODY_MENUBARTOGGLEFLAG_H
#define INC_3DBODY_MENUBARTOGGLEFLAG_H


namespace gf {

    class MenuBarToggleFlag final {
    public:
        MenuBarToggleFlag(const MenuBarToggleFlag &) = delete;

        void operator=(const MenuBarToggleFlag &e) = delete;

    private:
        MenuBarToggleFlag() {}

        ///file toggle switch.
        static bool newSelectedFlag;
        static bool newEnabledFlag;
        static bool newFromFileSelectedFlag;
        static bool newFromFileEnabledFlag;
        static bool newFromInternetSelectedFlag;
        static bool newFromInternetEnabledFlag;
        static bool saveSelectedFlag;
        static bool saveEnabledFlag;
        static bool saveAsSelectedFlag;
        static bool saveAsEnabledFlag;

        ///edit toggle switch.
        static bool undoSelectedFlag;
        static bool undoEnabledFlag;
        static bool redoSelectedFlag;
        static bool redoEnabledFlag;
        static bool cutSelectedFlag;
        static bool cutEnabledFlag;
        static bool copySelectedFlag;
        static bool copyEnabledFlag;
        static bool pasteSelectedFlag;
        static bool pasteEnabledFlag;

        ///scripts toggle switch.
        static bool pythonScriptSelectedFlag;
        static bool pythonScriptEnabledFlag;
        static bool luaScriptSelectedFlag;
        static bool luaScriptEnabledFlag;
        static bool shellScriptSelectedFlag;
        static bool shellScriptEnabledFlag;
        static bool fortranScriptSelectedFlag;
        static bool fortranScriptEnabledFlag;
        static bool matlabScriptEnabledFlag;
        static bool matlabScriptSelectedFlag;

        ///tools toggle switch.
        static bool slamSelectedFlag;
        static bool slamEnabledFlag;
        static bool shapeAnalysisSelectedFlag;
        static bool shapeAnalysisEnabledFlag;
        static bool modelEditingSelectedFlag;
        static bool modelEditingEnabledFlag;
        static bool rigidFEMSelectedFlag;
        static bool rigidFEMEnabledFlag;
        static bool fluidSimulationSelectedFlag;
        static bool fluidSimulationEnabledFlag;

        ///windows toggle switch.
        static bool upViewSelectedFlag;
        static bool upViewEnabledFlag;
        static bool frontViewSelectedFlag;
        static bool frontViewEnabledFlag;
        static bool leftViewSelectedFlag;
        static bool leftViewEnabledFlag;
        static bool gizmoSelectedFlag;
        static bool gizmoEnabledFlag;
        static bool styleSelectedFlag;
        static bool styleEnabledFlag;
        static bool cameraSelectedFlag;
        static bool cameraEnabledFlag;
        static bool lightSelectedFlag;
        static bool lightEnabledFlag;
        static bool materialsSelectedFlag;
        static bool materialsEnabledFlag;
        static bool generalSettingSelectedFlag;
        static bool generalSettingEnabledFlag;

        ///help toggle switch.
        static bool helpSelectedFlag;
        static bool helpEnabledFlag;
        static bool gettingStartSelectedFlag;
        static bool gettingStartEnabledFlag;
        static bool tipsSelectedFlag;
        static bool tipsEnabledFlag;
        static bool bugReportSelectedFlag;
        static bool bugReportEnabledFlag;
        static bool suggestionSelectedFlag;
        static bool suggestionEnabledFlag;
        static bool registerSelectedFlag;
        static bool registerEnabledFlag;
        static bool updateSelectedFlag;
        static bool updateEnabledFlag;
        static bool supportSelectedFlag;
        static bool supportEnabledFlag;
        static bool aboutSelectedFlag;
        static bool aboutEnabledFlag;


    };

    ///file toggle switch.
    bool MenuBarToggleFlag::newSelectedFlag             = true;
    bool MenuBarToggleFlag::newEnabledFlag              = true;
    bool MenuBarToggleFlag::newFromFileSelectedFlag     = true;
    bool MenuBarToggleFlag::newFromFileEnabledFlag      = true;
    bool MenuBarToggleFlag::newFromInternetSelectedFlag = true;
    bool MenuBarToggleFlag::newFromInternetEnabledFlag  = true;
    bool MenuBarToggleFlag::saveSelectedFlag            = true;
    bool MenuBarToggleFlag::saveEnabledFlag             = true;
    bool MenuBarToggleFlag::saveAsSelectedFlag          = true;
    bool MenuBarToggleFlag::saveAsEnabledFlag           = true;

    ///edit toggle switch.
    bool MenuBarToggleFlag::undoSelectedFlag  = true;
    bool MenuBarToggleFlag::undoEnabledFlag   = true;
    bool MenuBarToggleFlag::redoSelectedFlag  = true;
    bool MenuBarToggleFlag::redoEnabledFlag   = true;
    bool MenuBarToggleFlag::cutSelectedFlag   = true;
    bool MenuBarToggleFlag::cutEnabledFlag    = true;
    bool MenuBarToggleFlag::copySelectedFlag  = true;
    bool MenuBarToggleFlag::copyEnabledFlag   = true;
    bool MenuBarToggleFlag::pasteSelectedFlag = true;
    bool MenuBarToggleFlag::pasteEnabledFlag  = true;

    ///script toggle switch.
    bool MenuBarToggleFlag::pythonScriptSelectedFlag  = true;
    bool MenuBarToggleFlag::pythonScriptEnabledFlag   = true;
    bool MenuBarToggleFlag::luaScriptSelectedFlag     = false;
    bool MenuBarToggleFlag::luaScriptEnabledFlag      = false;
    bool MenuBarToggleFlag::shellScriptSelectedFlag   = true;
    bool MenuBarToggleFlag::shellScriptEnabledFlag    = true;
    bool MenuBarToggleFlag::fortranScriptSelectedFlag = false;
    bool MenuBarToggleFlag::fortranScriptEnabledFlag  = false;
    bool MenuBarToggleFlag::matlabScriptEnabledFlag   = false;
    bool MenuBarToggleFlag::matlabScriptSelectedFlag  = false;

    ///tools toggle switch.
    bool MenuBarToggleFlag::slamSelectedFlag            = true;
    bool MenuBarToggleFlag::slamEnabledFlag             = true;
    bool MenuBarToggleFlag::shapeAnalysisSelectedFlag   = false;
    bool MenuBarToggleFlag::shapeAnalysisEnabledFlag    = false;
    bool MenuBarToggleFlag::modelEditingSelectedFlag    = false;
    bool MenuBarToggleFlag::modelEditingEnabledFlag     = false;
    bool MenuBarToggleFlag::rigidFEMSelectedFlag        = false;
    bool MenuBarToggleFlag::rigidFEMEnabledFlag         = false;
    bool MenuBarToggleFlag::fluidSimulationSelectedFlag = false;
    bool MenuBarToggleFlag::fluidSimulationEnabledFlag  = false;

    ///windows toggle switch.
    bool MenuBarToggleFlag::upViewSelectedFlag         = true;
    bool MenuBarToggleFlag::upViewEnabledFlag          = true;
    bool MenuBarToggleFlag::frontViewSelectedFlag      = true;
    bool MenuBarToggleFlag::frontViewEnabledFlag       = true;
    bool MenuBarToggleFlag::leftViewSelectedFlag       = true;
    bool MenuBarToggleFlag::leftViewEnabledFlag        = true;
    bool MenuBarToggleFlag::gizmoSelectedFlag          = true;
    bool MenuBarToggleFlag::gizmoEnabledFlag           = true;
    bool MenuBarToggleFlag::styleSelectedFlag          = true;
    bool MenuBarToggleFlag::styleEnabledFlag           = true;
    bool MenuBarToggleFlag::cameraSelectedFlag         = false;
    bool MenuBarToggleFlag::cameraEnabledFlag          = false;
    bool MenuBarToggleFlag::lightSelectedFlag          = false;
    bool MenuBarToggleFlag::lightEnabledFlag           = false;
    bool MenuBarToggleFlag::materialsSelectedFlag      = false;
    bool MenuBarToggleFlag::materialsEnabledFlag       = false;
    bool MenuBarToggleFlag::generalSettingSelectedFlag = true;
    bool MenuBarToggleFlag::generalSettingEnabledFlag  = true;

    ///help toggle switch.
    bool MenuBarToggleFlag::helpSelectedFlag         = true;
    bool MenuBarToggleFlag::helpEnabledFlag          = true;
    bool MenuBarToggleFlag::gettingStartSelectedFlag = true;
    bool MenuBarToggleFlag::gettingStartEnabledFlag  = true;
    bool MenuBarToggleFlag::tipsSelectedFlag         = true;
    bool MenuBarToggleFlag::tipsEnabledFlag          = true;
    bool MenuBarToggleFlag::bugReportSelectedFlag    = true;
    bool MenuBarToggleFlag::bugReportEnabledFlag     = true;
    bool MenuBarToggleFlag::suggestionSelectedFlag   = true;
    bool MenuBarToggleFlag::suggestionEnabledFlag    = true;
    bool MenuBarToggleFlag::registerSelectedFlag     = true;
    bool MenuBarToggleFlag::registerEnabledFlag      = true;
    bool MenuBarToggleFlag::updateSelectedFlag       = true;
    bool MenuBarToggleFlag::updateEnabledFlag        = true;
    bool MenuBarToggleFlag::supportSelectedFlag      = true;
    bool MenuBarToggleFlag::supportEnabledFlag       = true;
    bool MenuBarToggleFlag::aboutSelectedFlag        = true;
    bool MenuBarToggleFlag::aboutEnabledFlag         = true;

}


#endif //INC_3DBODY_MENUBARTOGGLEFLAG_H
