package org.mavlink.qgroundcontrol;

// 导入必要的 ZeroTier One 的库文件和 Android API
public class ZeroTierWrapper {

    // 加载 ZeroTier 的 JNI 库
    static {
        System.loadLibrary("ZeroTierOneJNI");
    }

    // 初始化 ZeroTier
    public static void initializeZeroTier() {
        // 这里的实现调用了 JNI 的 native 方法
        ZeroTierWrapper.nativeInitializeZeroTier();
    }

    // 加入 ZeroTier 网络
    public static void joinNetwork(String networkId) {
        // 将网络 ID 传递给 native 方法
        ZeroTierWrapper.nativeJoinNetwork(networkId);
    }

    // 离开 ZeroTier 网络
    public static void leaveNetwork(String networkId) {
        // 调用 native 方法以离开网络
        ZeroTierWrapper.nativeLeaveNetwork(networkId);
    }

    // 获取 ZeroTier 网络状态
    public static String getStatus() {
        // 通过 JNI 获取状态并返回
        return ZeroTierWrapper.nativeGetStatus();
    }

    // 声明 Native 方法
    private static native void nativeInitializeZeroTier();
    private static native void nativeJoinNetwork(String networkId);
    private static native void nativeLeaveNetwork(String networkId);
    private static native String nativeGetStatus();
}
