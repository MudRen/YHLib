inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
��һ���������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ����
�Ű�����һ���ſ������������˿��ˣ������̸Ц����ͷ��
������Ҫ����������ƹʺ�ҥ�ԣ������Ǹ������ڡ�
LONG );
	set("resource/water", 1);

	set("exits", ([
	       "north" : __DIR__"hengyang",
	]));

	set("objects", ([
		__DIR__"npc/chaboshi" : 1,
	]));

	setup();
	replace_program(ROOM);
}

