inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
����һ��ͨ���ɶ��Ĵ���ʯ��������������Σ�����ʮ��
���¡��ɶ�ƽԭ����츮֮������Ұ����Ȯ�ͣ���������һ��
������Ϣ�������������Կ����ɶ������ˡ�
LONG);
	set("outdoors", "chengdu");
	set("exits", ([
	    "southeast" : __DIR__"road1",
	    "west"      : __DIR__"fuheqiaoe",
	    "east"      : __DIR__"shudao19",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

