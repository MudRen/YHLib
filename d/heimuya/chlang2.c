inherit ROOM;

void create()
{
  	set("short","����");
  	set("long", @LONG
�����Ƿǳ����ɵĳ��ȡ�����ȴûʲô��������ϱ���
�����õĴ�����
LONG);

  	set("exits",([
      		"north" : __DIR__"chlang1",
      		"south" : __DIR__"qing",
  	]));
  	set("no_clean_up", 0);
  	setup();
  	replace_program(ROOM);
}
