inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
һ����������¿���һ����̤����һ�ѿݹǡ�����һ����
���������������������ɢ���������Ǻ��ǡ������ֻ����
�󵶺����ۣ��߲���͹��������������ǰ�У����һ�ѶѰ�
�ǣ�ת�˸��䣬ǰ��ͻȻ����һ����
LONG);
	set("exits", ([
		"east" : __DIR__"dadian",
		"south" : __DIR__"yongdao3",
	]));

        set("objects", ([
                __DIR__"obj/yufu" : random(2),
                __DIR__"obj/yudao" : random(2),
                __DIR__"obj/yujian" : random(2),
                __DIR__"obj/skeleton" : random(3) + 1,
        ]));

	setup();
	replace_program(ROOM);
}
