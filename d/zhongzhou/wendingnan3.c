inherit ROOM;

void create()
{
	set("short", "�Ķ��Ͻ�");
	set("long", @LONG
�������ݳ��Ķ��Ͻ֣����Ľֵ����˲�������һ������
����һ�Ҳ�С�ķ��ӣ�����Ů�����ų����˵�΢Ц���϶��Ǹ�
���ɵĺõط��������������ں�����С��ͬ��
LONG);
	set("outdoors", "zhongzhou");
	set("objects", ([
  		"/d/beijing/npc/boy3" : 2,
	]));

	set("exits", ([
  		"south" : __DIR__"wendingnan4",
  		"northeast" : __DIR__"hutong",
  		"north" : __DIR__"wendingnan2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
