inherit ROOM;

void create()
{
	set("short", "ؤ�����ݷֶ�");
	set("long", @LONG
������ؤ���������ݸ��ķֶ档���������ɢ����һЩ��
�ݺ����ޱ������е��������ѱ��˰��ߣ����һ��л���ռ
�˵ط�����ֻ���߹�ɢ�������и�����ԭ����ʢ��ˮ�ġ�
LONG);
	set("no_clean_up", 0);
	set("outdoors", "zhongzhou");
	set("exits", ([
  		"out" : __DIR__"guandimiao",
	]));
	set("objects", ([
                "/clone/npc/walker" : 1,
	]));
	setup();
	replace_program(ROOM);
}
