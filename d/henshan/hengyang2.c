inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ǻ������֣��������߱���������ˣ�������һ����
���̣��ϱ���һ��ƫƧ��С�
LONG);
        set("outdoors", "henshan");

	set("exits", ([
	       "east"   : __DIR__"hsroad3",
	       "west"   : __DIR__"hengyang",
	       "south"  : __DIR__"xiaoxiang1",
	       "north"  : __DIR__"zahuopu",
	]));

        set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

