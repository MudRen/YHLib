inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����������֣������߳�û���ϱ�����ݴԡ�������һ��
���Ҷ��������洫��һ��˻˻��������
LONG);
        set("outdoors", "baituo");
        set("exits",([
                "northup" : __DIR__"cave",
                "south"   : __DIR__"cao2",
        ]));
        set("objects",([
                "/clone/beast/qingshe" : random(3),
                "/clone/beast/dushe" : random(2),
        ]));
        set("quarrys", ([
                "caihuashe"  : 100000,
                "dushe"      : 50000,
                "jinshe"     : 40000,
                "qingshe"    : 40000,
                "yanjingshe" : 5000,
                "mangshe"    : 3000,
        ]));
        setup();
        replace_program(ROOM);
}
