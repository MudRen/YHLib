inherit ROOM;

void create()
{
        set("short", "�嶫��");
        set("long", @LONG
������С��Ķ�ͷ����Ϊ����չ�������һƬ��Ţ��·�ǳ�����
�ߡ�˳������·һֱ����һ����ʱ���Ϳɵ���ʯƺ�ˣ��������⸽
���������ӡ�
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "northwest" : __DIR__"cun7",
                "east" : "/d/dali/zhulin2",
        ]));

        setup();
        replace_program(ROOM);
}
