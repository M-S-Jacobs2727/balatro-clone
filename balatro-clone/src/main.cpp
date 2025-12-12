#include "AppLayer.h"
#include "Application.h"
#include "OverlayLayer.h"

int main()
{
    Core::ApplicationSpecification appSpec;
    appSpec.name = "Architecture";
    appSpec.windowSpec.width = 1920;
    appSpec.windowSpec.height = 1080;

    Core::Application application(appSpec);
    application.pushLayer<AppLayer>();
    application.pushLayer<OverlayLayer>();
    application.run();
}