inherit ROOM;

void create()
{
	set("short", "������Ժ");
	set("long", @LONG
����ԭ�������¡������Ļ��������͸ĳ���������Ժ����
�����Ժ����´��Ժ����¹��Ժ�ϳ����� "�Ĵ���Ժ" ������
���������ڴ˽�ѧ��Ժ���йŰ����꣬�����Ѳ�����ˣ���
��Ϊ�󽫾�������������������
LONG );
	set("exits", ([
		"southdown" : __DIR__"shandao2",
		"northwest" : __DIR__"shandao3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

