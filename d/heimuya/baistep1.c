inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
�����ǰ׻��õĳ��ȣ�����ɨ�÷ǳ��ĸɾ�����ʱ������
�����˰׻��õĵ����ڴ��߶���
LONG);
  	set("exits",([
      		"east" : __DIR__"dating2",
      		"south" : __DIR__"baistep2",
  	]));
  	set("objects",([
     		__DIR__"npc/shinu" : 2,
  	]));
  	setup();
  	replace_program(ROOM);
}
