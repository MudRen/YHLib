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
                "westdown" : __DIR__"wdsl5",
                "south" : __DIR__"sl1",
        ]));

        setup();
        replace_program(ROOM);
}
