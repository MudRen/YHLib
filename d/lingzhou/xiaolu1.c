inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
���Ƕ����ϵ�һ���Ӳݴ�������С·��������ƽʱûʲ
ô�˼���·�߿��Ų�֪��Ұ��������������Ȼ�ߴ�ͦ�Ρ�����
͸�����յ��������ǰ߲߰�����Ӱ�ӡ�
LONG );
	set("exits", ([
		"south"     : __DIR__"dalu",
		"north"     : __DIR__"xiaolu2",
	]));
	set("objects", ([
		"/clone/quarry/tu" : 1,
	]));
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

