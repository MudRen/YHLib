inherit ROOM;

void create()
{
        set("short", "���϶�");
        set("long", @LONG
����Ƕ��ҵ�һ�󶴣���������ޱȣ������Ѳ⡣��һ��
�������㷢�����в涴�����Թ�������Ī���ƺ�����޵ס���
�ǿ���뿪�ɡ�
LONG);
        set("objects", ([
                "/clone/quarry/fu" : 4,
        ]));
        set("exits", ([
                "out"   : __DIR__"jldongkou",
                "north" : __DIR__"jldongnei",
        ]));
        setup();
        replace_program(ROOM);
}
