inherit ROOM;

void create()
{
        set("short", "̫����");
        set("long", @LONG
�˴��ش�����֮����������Ҫ���ഫ���ֹ�̫����������
��ɽ�޵�ʱ�����ڴ���ס���飬������̫���£�����һ���ˮ
ܽ�أ�ӿ���̲�����������������Զ�����·ת����������
������֮�С�
LONG);
        set("exits", ([
                "northdown"  : __DIR__"shanlu1",
                "southdown"  : __DIR__"shiliang",
                "east"       : __DIR__"fuzhenguan",
        ]));
        set("outdoors", "wudang");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
