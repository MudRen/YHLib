inherit ROOM;

void create()
{
  	set("short", "Ϸ�����¥");
  	set("long", @LONG
��������¥���˱�¥�µ��ٶ��ˣ�ֻ����¥������ԼԼ��
���������壬����ô���С�
LONG);
  	set("exits",([
      		"down" : __DIR__"liangong2",
  	]));
  	set("for_family", "���չ�");
  	setup();
  	replace_program(ROOM);
}
