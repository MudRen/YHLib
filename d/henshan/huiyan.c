inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
�����Ǻ�������¥���Ǳ������ľ�¥��������ʱ�Ѿ�ʮ
��æµ�ľ�¥����ȴ�е�������һ�������ʮ�İ��º��ӣ���
������������������һ�ѿ쵶���Ա�ȴ����һ��С��ã���
���Ǽ����֮ɫ����òȴʮ��������
LONG);
	set("exits", ([
	       "down" : __DIR__"shop",
	]));
	set("objects", ([
	        __DIR__"npc/tian"   : 1,
	        __DIR__"npc/yilin"  : 1,
	]));

        set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

