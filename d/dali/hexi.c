inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���������������ϣ�ס���ǰ�޼�������Բ�����޼����̨
�ģ�������˸����غ�������⣬��Ҫ�Բ���Ϊ�����ٺ����
�������������߲�Զ�����洬�����С��ͷ���ϱ�ɽ���в���
Ұ�ޣ����Բ������Ӿ���ǰȥ���ԡ�
LONG);
        set("objects", ([
                __DIR__"npc/tshangfan": 1,
        ]));
        set("outdoors", "dali");
        set("exits", ([
                "northeast" : __DIR__"feilihueast",
                "west"      : __DIR__"yujia",
                "north"     : __DIR__"feilihusouth",
                "south"     : __DIR__"zhulin2",
        ]));
        setup();
        replace_program(ROOM);
}
