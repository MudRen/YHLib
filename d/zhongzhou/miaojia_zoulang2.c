inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ľ�Ƶ����ȣ�������ǹ⻬����������һ����Ⱦ��
������ҵ�Ѿ���ڴ��߶������ȵı�����һ��Ժ�ӡ�
LONG);
	set("exits", ([
  		"south" : __DIR__"miaojia_houting",
  		"north" : __DIR__"miaojia_houyuan",
	]));
	set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}
