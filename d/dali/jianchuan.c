inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǽ����������ģ����Ӳ��󣬾�����󲿷���������
����ȫ��������Ϊ��������ɽ�ߵغ�������ɽ�ֵ�Ұ�޴��Ƥ
��ë���в���Ƥ����������͵������˽��ס�����ɽ������
��������Ҳ������֮;���ϴ���ɽ��ɵִ�����½��
LONG);
        set("objects", ([
                __DIR__"npc/lieren" : 1,
                __DIR__"npc/pihuoshang": 1,
        ]));
        set("outdoors", "dali");
        set("exits", ([
                "north" : __DIR__"jianchuankou",
                "south" : __DIR__"cangshanzhong",
        ]));
        setup();
        replace_program(ROOM);
}
