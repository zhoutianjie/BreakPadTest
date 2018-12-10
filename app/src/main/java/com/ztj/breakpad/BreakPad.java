package com.ztj.breakpad;

/**
 * Created by zhoutianjie on 2018/12/10.
 */

public class BreakPad {

    static {
        System.loadLibrary("breakpad");
    }

    public static native void BreakPadInit(String path);

    public static native void BreakPadTest();
}
