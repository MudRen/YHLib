inherit ROOM;

void create()
{
  	set("short", "���᷿");
  	set("long", @LONG
������������̳ɵµ�ĺ���������᷿�����ڰ���һ��
Ѭ��󴲣��������ŵ���������������˯���ǳ������û����
���š����������ɵĳ��ȡ�
LONG );
  	set("exits",([
      		"west" : __DIR__"huoting",
  	]));
  	set("sleep_room", 1);
  	set("no_fight",1);
  	set("no_steal",1);
  	set("no_clean_up", 0);
  	setup();
  	replace_program(ROOM);
}

