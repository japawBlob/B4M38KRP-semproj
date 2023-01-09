// C:\Users\Public\B4M38KRP-semproj\usb_report_util\volume1.h


char ReportDescriptor[19] = {
    0x05, 0x0c,                    // USAGE_PAGE (Consumer Devices)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x85, 0x03,                    //   REPORT_ID (3)
    0x09, 0xe0,                    //   USAGE (Volume)
    0x15, 0x81,                    //   LOGICAL_MINIMUM (-127)
    0x25, 0x7f,                    //   LOGICAL_MAXIMUM (127)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x81, 0x06,                    //   INPUT (Data,Var,Rel)
    0xc0                           // END_COLLECTION
};

