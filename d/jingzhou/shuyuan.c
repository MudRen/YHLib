inherit ROOM;

void create()
{
	set("short", "������Ժ");
	set("long", @LONG
��������Ժ�Ľ��ã�����������һ����Ⱦ��һλׯ������
����������̫ʦ���Ͻ�ѧ���Ǿ��ǵ�����庫�����ˡ�������
������������ѧ��ѧ����һ�Ź��ⰻȻ���鰸������������ǰ
�棬���ϰ��ż��������˵���װ�鼮��
LONG);
	set("exits", ([
  		"north" : __DIR__"dongdajie1",
  		"south" : __DIR__"shuyuan1",
	]));
	set("objects", ([
  		__DIR__"npc/xiaoxiang" : 1,
                "/d/wudu/npc/xuetong" : 2,
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
