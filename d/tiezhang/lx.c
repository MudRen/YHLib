// Room: /u/zqb/tiezhang/lx.c

inherit ROOM;

void create()
{
	set("short", "��Ϫ");
	set("long", @LONG
������������һ��С����Ȼ�˵صش�ƫƧ��������������������Ȼ��
�ࡣ������һ�乩����Ϣ����С�͵ꡣ���Ϸ���ʮ�ﴦ�����Ǵ˴�������
��צɽ��
LONG	);
	set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 3 */
		"southwest" : __DIR__"road-1",
		"north" : __DIR__"hunanroad2",
		"west" : __DIR__"kedian",
	]));

	setup();
	replace_program(ROOM);
}
