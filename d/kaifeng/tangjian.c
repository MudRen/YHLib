inherit ROOM;

void create()
{
        set("short", "�ü�");
        set("long", @LONG
һ���ķ����ü䣬���еĹ����󻹰������ȱ�ķ�����
��ȱ�˰���Դ������ϰ���֩������ס�ˣ�Ҳ������ԭ����
ģ����һ�ߵ������Դ��˸����̣���ǽ���ż���ˮ�ޡ�
LONG);
        set("objects", ([
  		__DIR__"npc/oldseng" : 1,
	]));
        set("no_clean_up", 0);
        set("exits", ([
  		"west" : __DIR__"kongdi",
	]));

        setup();
        replace_program(ROOM);
}
