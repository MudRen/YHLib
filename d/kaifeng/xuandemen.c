inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������ǿ���ı����ţ��������������ǻʳ����ڡ���ǽ
�����ø����ι̡����ߵĲر���������ǧ�ˣ��������ǵ�����
���Ƴ���֮ʱ���ɷ���ɱ������ɱ���ˡ�
LONG);
        set("objects", ([
  		__DIR__"npc/guanbing" : 2,
	]));
        set("no_clean_up", 0);
        set("outdoors", "kaifeng");
        set("exits", ([
  		"south" : __DIR__"road6",
  		"north" : __DIR__"jiaowai",
	]));

        setup();
        replace_program(ROOM);
}
