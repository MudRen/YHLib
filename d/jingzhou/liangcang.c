inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Ǿ��������ˣ����϶��������������װ���ǰ�
�ȴ���֮�����ʳ��
LONG);
	set("exits", ([
		"west" : __DIR__"lcmen",
	]));

	setup();
	replace_program(ROOM);
}

