inherit ROOM;

void create()
{
	set("short", "����Ȫ");
	set("long", @LONG
��ɽ��������һ����Ȫ��ϵ�ϳ�������ɮ�������������䣬
���һǧ�İٶ��ꡣ��˵Ȫ��ͨ��������������ӿȪ����ˮ��
����Ϊ�����µ���Ȫ����ʯ�̡�����Ȫ�����֣�ϵ����������
���⡣
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"wanjing",
	]));
	setup();
	replace_program(ROOM);
}

