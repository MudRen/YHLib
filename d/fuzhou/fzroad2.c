inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
������խխ������ɽС���ϣ�ɽ·��᫣�����ɭɭ������
����Ұ�޳�û����ν��������������ѡ��ϲ����ۡ��������
����Ϫ������������ڶ��ϵ�����ɽ�ˡ�
LONG);
	set("exits", ([
		"northup" : __DIR__"erbapu",
		"southup" : __DIR__"fzroad3",
		"west"    : __DIR__"wuyishan1",
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

