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
                "eastup" : __DIR__"wdsl2",
                "southup" : __DIR__"wdsl3",
                "west" : __DIR__"taohua",
        ]));

        setup();
        replace_program(ROOM);
}

