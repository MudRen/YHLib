inherit ROOM;

void create()
{
        set("short", "���ݱ���");
        set("long", @LONG
�����Ѿ��������ݵı����ˣ��߸ߵĳ�ǽ��ש���ﳤ����
�ݡ��߹����ţ��ٹ��˻��Ǻӣ����ǳ����ˡ�
LONG);
        set("outdoors", "zhongzhou");
        set("exits", ([
  		"north" : __DIR__"to_zhongzhou3",
  		"south" : __DIR__"wendingbei4",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
  		"/d/kaifeng/npc/guanbing" : 4,
  		"/d/beijing/npc/ducha" : 1,
	]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
