inherit ROOM;
void create()
{
  	set("short","����");
  	set("long", @LONG
���Ƿ������ú�ĳ�����һλ������Ů������Ц��������
�������֬��������
LONG);
  	set("exits",([
      		"east" : __DIR__"grass2",
  	]));

  	set("objects",([
      		__DIR__"npc/shinu" : 1,
      		__DIR__"obj/tea" : 1 + random(6),
      		__DIR__"obj/sherou" : 1 + random(4),
  	]));
  	setup();
        replace_program(ROOM);
}
