inherit ROOM;

void create()
{
        set("short", "�嶾ɽ·");
        set("long", @LONG
�������嶾ɽ�е�ɽ��С·�����������������ϡ�ɽ·�ϼž���
����������һ˿���޵ĺۼ�����˳�ֲ�������·�е�֦������֦��Ȼ
һ�������˻�ȥ����Ȼ��һ�����ƿ�֦�Ķ��ߡ� 
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "eastup" : __DIR__"wdsl8",
                "westdown" : __DIR__"wdsl4",
                "north" : __DIR__"wdsl6",
        ]));

        setup();
        replace_program(ROOM);
}
