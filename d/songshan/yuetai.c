
inherit ROOM;

void create()
{
	set("short", "��̨");
	set("long", @LONG
������Ƿ����µ���̨������̨������̫��ɽ�͸������ƣ�
�¶���˫����ƣ��м����硣���� "����" ������ѽڣ�����
�Է���������������֮�У���������ɽ�ȣ�����ǵǷ�˾�
֮һ�ġ����Ŵ��¡���
LONG );
	set("exits", ([
		"east" : __DIR__"fawangsi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	setup();
	replace_program(ROOM);
}

