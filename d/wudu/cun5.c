inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
����С���ʯ��·�ϣ����Զ�������ʯ���ɵķ��ݡ������ﾲ��
�ĵģ����������ˣ�ż������һ�������С� 
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "southwest" : __DIR__"cun4",
                "southeast" : __DIR__"cun7",
                "north" : __DIR__"minju4",
        ]));

        setup();
}
