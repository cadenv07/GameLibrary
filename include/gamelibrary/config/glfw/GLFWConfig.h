/***************************************************\
* @file GLFWConfig.h
* @brief Header file containing structs for the
* configuration of various GLFW elements throughout
* the program.
*
* @author cadenv07
* @date 10/23/26
\***************************************************/

#pragma once

#include <GLFW/glfw3.h>

namespace GameLibrary {
    /**
     * @struct GLFWInstanceConfig
     *
     * @brief Configuration for creating the GLFW instance.
     */
    struct GLFWInstanceConfig {
        /**
         * @brief Specifies the platform to use for windowing and input.
         *
         * @details Possible values are:
         *  - GLFW_ANY_PLATFORM
         *  - GLFW_PLATFORM_WIN32
         *  - GLFW_PLATFORM_COCOA
         *  - GLFW_PLATFORM_WAYLAND
         *  - GLFW_PLATFORM_X11
         *  - GLFW_PLATFORM_NULL
         *
         * @note Default: GLFW_ANY_PLATFORM
         */
        GLint glfwPlatform = GLFW_ANY_PLATFORM;
        /**
         * @brief Specifies whether to also expose joystick hats as buttons.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_TRUE
         */
        GLint glfwJoystickHatButtons = GLFW_TRUE;
        /**
         * @brief Specifies the platform type (rendering backend) to request when using OpenGL ES and EGL.
         *
         * @details Possible values are:
         *  - GLFW_ANGLE_PLATFORM_TYPE_NONE
         *  - GLFW_ANGLE_PLATFORM_TYPE_OPENGL
         *  - GLFW_ANGLE_PLATFORM_TYPE_OPENGLES
         *  - GLFW_ANGLE_PLATFORM_TYPE_D3D9
         *  - GLFW_ANGLE_PLATFORM_TYPE_D3D11
         *  - GLFW_ANGLE_PLATFORM_TYPE_VULKAN
         *  - GLFW_ANGLE_PLATFORM_TYPE_METAL
         *
         * @note Default: GLFW_ANGLE_PLATFORM_TYPE_NONE
         */
        GLint glfwAnglePlatformType = GLFW_ANGLE_PLATFORM_TYPE_NONE;
        /**
         * @brief Specific to macOS: Specifies whether to set the current directory to the application to the Contents/Resources subdirectory of the application's bundle.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_TRUE
         */
        GLint glfwCocoaChdirResources = GLFW_TRUE;
        /**
         * @brief Specific to macOS: Specifies whether to create the menu bar and dock icon when GLFW is initialized.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_TRUE
         */
        GLint glfwCocoaMenuBar = GLFW_TRUE;
        /**
         * @brief Specific to Wayland: Specifies whether to use libdecor for window decorations where available.
         *
         * @details Possible values are:
         *  - GLFW_WAYLAND_PREFER_LIBDECOR
         *  - GLFW_WAYLAND_DISABLE_LIBDECOR
         *
         * @note GLFW_WAYLAND_PREFER_LIBDECOR
         */
        GLint glfwWaylandLibDecor = GLFW_WAYLAND_PREFER_LIBDECOR;
        /**
         * @brief Specific to X11: Specifies whether to prever the VK_KHR_xcb_surface extension for creating Vulkan surfaces.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_TRUE
         */
        GLint glfwX11XCBVulkanSurface = GLFW_TRUE;
    };

    /**
     * @struct GLFWWindowConfig
     *
     * @brief Configuration for creating the GLFW window.
     */
    struct GLFWWindowConfig {
        /**
         * @brief Specifies if the window can be resized by the user.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_TRUE
         */
        GLint glfwResizable = GLFW_TRUE;
        /**
         * @brief Specifies whether the window will be initially visible.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_TRUE
         */
        GLint glfwVisible = GLFW_TRUE;
        /**
         * @brief Specifies whether the window will have window decorations.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_TRUE
         */
        GLint glfwDecorated = GLFW_TRUE;
        /**
         * @brief Specifies whether the window will be given input focus when created.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_TRUE
         */
        GLint glfwFocused = GLFW_TRUE;
        /**
         * @brief Specifies whether the full screen window will automatically iconify on input focus loss.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_TRUE
         */
        GLint glfwAutoIconify = GLFW_TRUE;
        /**
         * @brief Specifies whether the window will float above regular windows, also called always-on-top.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_FALSE
         */
        GLint glfwFloating = GLFW_FALSE;
        /**
         * @brief Specifies whether the window will be maximized when created.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_FALSE
         */
        GLint glfwMaximized = GLFW_FALSE;
        /**
         * @brief Specifies whether the cursor should be centered on window creation.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_TRUE
         */
        GLint glfwCenterCursor = GLFW_TRUE;
        /**
         * @brief Specifies whether the windows framebuffer will be transparent.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_FALSE
         */
        GLint glfwTransparentFramebuffer = GLFW_FALSE;
        /**
         * @brief Specifies whether the window should be given focus input whenever glfwShowWindow is called.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_TRUE
         */
        GLint glfwFocusOnShow = GLFW_TRUE;
        /**
         * @brief Specifies whether the window content area should be resized based on content scale changes.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_FALSE
         */
        GLint glfwScaleToMonitor = GLFW_FALSE;
        /**
         * @brief Specifies whether the framebuffer should be resized based on content scale changes.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_TRUE
         */
        GLint glfwScaleFramebuffer = GLFW_TRUE;
        /**
         * @brief Specifies whether the window is transparent to mouse input.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_FALSE
         */
        GLint glfwMousePassthrough = GLFW_FALSE;
        /**
         * @brief Specifies the desired initial X position of the window.
         *
         * @details Possible values are:
         *  - GLFW_ANY_POSITION
         *
         * @note Default: GLFW_ANY_POSITION
         */
        GLint glfwPositionX = GLFW_ANY_POSITION;
        /**
         * @brief Specifies the desired initial Y position of the window.
         *
         * @details Possible values are:
         *  - GLFW_ANY_POSITION
         *
         * @note Default: GLFW_ANY_POSITION
         */
        GLint glfwPositionY = GLFW_ANY_POSITION;
        /**
         * @brief Specifies the desired red bit depth of the default framebuffer.
         *
         * @note Default: 8
         */
        GLint glfwRedBits = 8;
        /**
         * @brief Specifies the desired green bit depth of the default framebuffer.
         *
         * @note Default: 8
         */
        GLint glfwGreenBits = 8;
        /**
         * @brief Specifies the desired blue bit depth of the default framebuffer.
         *
         * @note Default: 8
         */
        GLint glfwBlueBits = 8;
        /**
         * @brief Specifies the desired alpha bit depth of the default framebuffer.
         *
         * @note Default: 8
         */
        GLint glfwAlphaBits = 8;
        /**
         * @brief Specifies the desired depth bit depth of the default framebuffer.
         *
         * @note Default: 24
         */
        GLint glfwDepthBits = 24;
        /**
         * @brief Specifies the desired stencil bit depth of the default framebuffer.
         *
         * @note Default: 8
         */
        GLint glfwStencilBits = 8;
        /**
         * @brief Specifies the desired red bit depth of the accumulation buffer.
         *
         * @note Default: 0
         */
        GLint glfwAccumRedBits = 0;
        /**
         * @brief Specifies the desired green bit depth of the accumulation buffer.
         *
         * @note Default: 0
         */
        GLint glfwAccumGreenBits = 0;
        /**
         * @brief Specifies the desired blue bit depth of the accumulation buffer.
         *
         * @note Default: 0
         */
        GLint glfwAccumBlueBits = 0;
        /**
         * @brief Specifies the desired alpha bit depth of the accumulation buffer.
         *
         * @note Default: 0
         */
        GLint glfwAccumAlphaBits = 0;
        /**
         * @brief Specifies the desired number of auxiliary buffers.
         *
         * @note Default: 0
         */
        GLint glfwAuxBuffers = 0;
        /**
         * @brief Specifies the desired number of samples to use for multisampling.
         *
         * @note Default: 0
         */
        GLint glfwSamples = 0;
        /**
         * @brief Specifies the desired refresh rate for full screen windows.
         *
         * @note Default: GLFW_DONT_CARE
         */
        GLint glfwRefreshRate = GLFW_DONT_CARE;
        /**
         * @brief Specifies whether to use OpenGL stereoscopic rendering.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_FALSE
         */
        GLint glfwStereo = GLFW_FALSE;
        /**
         * @brief Specifies whether the window should be sRGB capable.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_FALSE
         */
        GLint glfwSRGBCapable = GLFW_FALSE;
        /**
         * @brief Specifies whether the framebuffer should be double buffered.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_TRUE
         */
        GLint glfwDoubleBuffer = GLFW_TRUE;
        /**
         * @brief Specifies which client API to create the context for.
         *
         * @details Possible values are:
         *  - GLFW_OPENGL_API
         *  - GLFW_OPENGL_ES_API
         *  - GLFW_NO_API
         *
         * @note Default: GLFW_OPENGL_API
         */
        GLint glfwClientApi = GLFW_OPENGL_API;
        /**
         * @brief Specifies which context creation API to use to create the context.
         *
         * @details Possible values are:
         *  - GLFW_NATIVE_CONTEXT_API
         *  - GLFW_EGL_CONTEXT_API
         *  - GLFW_OSMESA_CONTEXT_API
         *
         * @note Default: GLFW_NATIVE_CONTEXT_API
         */
        GLint glfwContextCreationApi = GLFW_NATIVE_CONTEXT_API;
        /**
         * @brief The major version of the requested client API.
         *
         * @note Default: 1
         */
        GLint glfwContextVersionMajor = 1;
        /**
         * @brief The minor version of the requested client API.
         *
         * @note Default: 0
         */
        GLint glfwContextVersionMinor = 0;
        /**
         * @brief Specifies the robustness strategy to be used by the context.
         *
         * @details Possible values are:
         *  - GLFW_NO_RESET_NOTIFICATION
         *  - GLFW_LOSE_CONTEXT_ON_RESET
         *  - GLFW_NO_ROBUSTNESS
         *
         * @note Default: GLFW_NO_ROBUSTNESS
         */
        GLint glfwContextRobustness = GLFW_NO_ROBUSTNESS;
        /**
         * @brief Specifies the release behavior to be used by the context.
         *
         * @details Possible values are:
         *  - GLFW_ANY_RELEASE_BEHAVIOR
         *  - GLFW_RELEASE_BEHAVIOR_FLUSH
         *  - GLFW_RELEASE_BEHAVIOR_NONE
         *
         * @note Default: GLFW_ANY_RELEASE_BEHAVIOR
         */
        GLint glfwContextReleaseBehavior = GLFW_ANY_RELEASE_BEHAVIOR;
        /**
         * @brief Specifies whether the OpenGL context should be forward-compatible.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_FALSE
         */
        GLint glfwOpenGLForwardCompat = GLFW_FALSE;
        /**
         * @brief Specifies whether the context should be created in debug mode,
         * which may provide additional error and diagnostic reporting functionality.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_FALSE
         */
        GLint glfwContextDebug = GLFW_FALSE;
        /**
         * @brief Specifies which OpenGL profile to create the context for.
         *
         * @details Possible values are:
         *  - GLFW_OPENGL_CORE_PROFILE
         *  - GLFW_OPENGL_COMPAT_PROFILE
         *  - GLFW_OPENGL_ANY_PROFILE
         *
         * @note Default: GLFW_OPENGL_ANY_PROFILE
         */
        GLint glfwOpenGLProfile = GLFW_OPENGL_ANY_PROFILE;
        /**
         * @brief Specifies whether to allow access to the window menu via the Alt+Space keyboard shortcut.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_FALSE
         */
        GLint glfwWin32KeyboardMenu = GLFW_FALSE;
        /**
         * @brief Specifies whether to show the window the way specified in the program's STARTUPINFO when shown for the first time.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_FALSE
         */
        GLint glfwWin32ShowDefault = GLFW_FALSE;
        /**
         * @brief Specific to macOS. Specifies the UTF-8 encoded name to use for autosaving the window frame.
         *
         * @note Default: ""
         */
        const char* glfwCocoaFrameName = "";
        /**
         * @brief Specific to macOS. Specifies whether to in Automatic Graphics Switching.
         *
         * @details Possible values are:
         *  - GLFW_TRUE
         *  - GLFW_FALSE
         *
         * @note Default: GLFW_FALSE
         */
        GLint glfwCocoaGraphicsSwitching = GLFW_FALSE;
        /**
         * @brief Specifies the Wayland app_id for a window, used to identify types of windows.
         *
         * @note Default: ""
         */
        const char* glfwWaylandAppId = "";
        /**
         * @brief Specifies the desired ASCII encoded class part of the ICCCM WM_CLASS window property.
         *
         * @note Default: ""
         */
        const char* glfwX11ClassName = "";
        /**
         * @brief Specifies the desired ASCII encoded instance part of the ICCCM WM_CLASS window property.
         *
         * @note Default: ""
         */
        const char* glfwX11InstanceName = "";
    };

    /**
     * @brief Initializes all GLFW init hints for context creation.
     *
     * @param[in] config The WindowConfig object to use for configuration.
     *
     * @pre Assumes that glfwInit() has not already been run.
     */
    inline void glfwInitHints(const GLFWInstanceConfig& config) {
        glfwInitHint(GLFW_PLATFORM, config.glfwPlatform);
        glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, config.glfwJoystickHatButtons);
        glfwInitHint(GLFW_ANGLE_PLATFORM_TYPE, config.glfwAnglePlatformType);
        glfwInitHint(GLFW_COCOA_CHDIR_RESOURCES, config.glfwCocoaChdirResources);
        glfwInitHint(GLFW_COCOA_MENUBAR, config.glfwCocoaMenuBar);
        glfwInitHint(GLFW_WAYLAND_LIBDECOR, config.glfwWaylandLibDecor);
        glfwInitHint(GLFW_X11_XCB_VULKAN_SURFACE, config.glfwX11XCBVulkanSurface);
    }



    /**
     * @brief Initializes all GLFW window hints for window creation.
     *
     * @param[in] config The WindowConfig object to use for configuration.
     *
     * @pre Assumes that glfwInit() has already been run.
     */
    inline void glfwWindowHints(const GLFWWindowConfig& config) {
        glfwWindowHint(GLFW_RESIZABLE, config.glfwResizable);
        glfwWindowHint(GLFW_VISIBLE, config.glfwVisible);
        glfwWindowHint(GLFW_DECORATED, config.glfwDecorated);
        glfwWindowHint(GLFW_FOCUSED, config.glfwFocused);
        glfwWindowHint(GLFW_AUTO_ICONIFY, config.glfwAutoIconify);
        glfwWindowHint(GLFW_FLOATING, config.glfwFloating);
        glfwWindowHint(GLFW_MAXIMIZED, config.glfwMaximized);
        glfwWindowHint(GLFW_CENTER_CURSOR, config.glfwCenterCursor);
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, config.glfwTransparentFramebuffer);
        glfwWindowHint(GLFW_FOCUS_ON_SHOW, config.glfwFocusOnShow);
        glfwWindowHint(GLFW_SCALE_TO_MONITOR, config.glfwScaleToMonitor);
        glfwWindowHint(GLFW_SCALE_FRAMEBUFFER, config.glfwScaleFramebuffer);
        glfwWindowHint(GLFW_MOUSE_PASSTHROUGH, config.glfwMousePassthrough);
        glfwWindowHint(GLFW_POSITION_X, config.glfwPositionX);
        glfwWindowHint(GLFW_POSITION_Y, config.glfwPositionY);
        glfwWindowHint(GLFW_RED_BITS, config.glfwRedBits);
        glfwWindowHint(GLFW_GREEN_BITS, config.glfwGreenBits);
        glfwWindowHint(GLFW_BLUE_BITS, config.glfwBlueBits);
        glfwWindowHint(GLFW_ALPHA_BITS, config.glfwAlphaBits);
        glfwWindowHint(GLFW_DEPTH_BITS, config.glfwDepthBits);
        glfwWindowHint(GLFW_STENCIL_BITS, config.glfwStencilBits);
        glfwWindowHint(GLFW_ACCUM_RED_BITS, config.glfwAccumRedBits);
        glfwWindowHint(GLFW_ACCUM_GREEN_BITS, config.glfwAccumRedBits);
        glfwWindowHint(GLFW_ACCUM_BLUE_BITS, config.glfwAccumRedBits);
        glfwWindowHint(GLFW_ACCUM_ALPHA_BITS, config.glfwAccumRedBits);
        glfwWindowHint(GLFW_AUX_BUFFERS, config.glfwAuxBuffers);
        glfwWindowHint(GLFW_SAMPLES, config.glfwSamples);
        glfwWindowHint(GLFW_REFRESH_RATE, config.glfwRefreshRate);
        glfwWindowHint(GLFW_STEREO, config.glfwStereo);
        glfwWindowHint(GLFW_SRGB_CAPABLE, config.glfwSRGBCapable);
        glfwWindowHint(GLFW_DOUBLEBUFFER, config.glfwDoubleBuffer);
        glfwWindowHint(GLFW_CLIENT_API, config.glfwClientApi);
        glfwWindowHint(GLFW_CONTEXT_CREATION_API, config.glfwContextCreationApi);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, config.glfwContextVersionMajor);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, config.glfwContextVersionMinor);
        glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, config.glfwContextRobustness);
        glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, config.glfwContextReleaseBehavior);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, config.glfwOpenGLForwardCompat);
        glfwWindowHint(GLFW_CONTEXT_DEBUG, config.glfwContextDebug);
        glfwWindowHint(GLFW_OPENGL_PROFILE, config.glfwOpenGLProfile);
        glfwWindowHint(GLFW_WIN32_KEYBOARD_MENU, config.glfwWin32KeyboardMenu);
        glfwWindowHint(GLFW_WIN32_SHOWDEFAULT, config.glfwWin32ShowDefault);
        glfwWindowHintString(GLFW_COCOA_FRAME_NAME, config.glfwCocoaFrameName);
        glfwWindowHint(GLFW_COCOA_GRAPHICS_SWITCHING, config.glfwCocoaGraphicsSwitching);
        glfwWindowHintString(GLFW_WAYLAND_APP_ID, config.glfwWaylandAppId);
        glfwWindowHintString(GLFW_X11_CLASS_NAME, config.glfwX11ClassName);
        glfwWindowHintString(GLFW_X11_INSTANCE_NAME, config.glfwX11InstanceName);
    }
}