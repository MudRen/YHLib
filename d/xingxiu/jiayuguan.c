inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���ǳ��������Ĺذ������²�ɣ�����ڲ�ס���ķ�ɡ�Ⱥ
ɽ����֮�£����������ۻ롣�������򰲶�������ս�£��߹�
�ؾ��Ѵ�Ϊ���١�һ�����������ͨ����ԭ��������������
��������˿��֮·��
LONG);
        set("outdoors", "xingxiu");
        set("exits", ([
                "eastup" : __DIR__"xxroad3",
                "west" : __DIR__"silk1",
        ]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
        setup();
        replace_program(ROOM);
}

