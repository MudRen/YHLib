inherit ROOM;

void create()
{
        set("short", "��վ");
        set("long", @LONG
���������ݳǵ���վ�������վ����һ���Ǹ�СС�Ĳ�
������ٲ��ڴ���š�
LONG);

        set("no_clean_up", 0);
        set("exits", ([
  		"west" : __DIR__"wendingnan4",
	]));

        setup();
        replace_program(ROOM);
}
