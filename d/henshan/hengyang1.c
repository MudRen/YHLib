inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
��������ʯ�̾͵���С�ֵ��ϡ�ֻ������ʱ�����˳ֽ���
�У��ƺ��������ɶ���ˡ��ϱ���һ��С�꣬����һ������Ρ
�룬���ܵ��ߣ� �ſڲʵƸ������ܼҼҶ��������������ˡ�
LONG);
        set("outdoors", "henshan");

	set("exits", ([
	       "east"   : __DIR__"hengyang",
	       "west"   : __DIR__"hengyang11",
	       "south"  : __DIR__"shop",
	       "north"  : __DIR__"liufugate",
	]));

        set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

