inherit ROOM;

void create()
{
  	set("short","����");
  	set("long", @LONG
�����ǰ׻��õĳ��ȣ�����ɨ�÷ǳ��ĸɾ�����ʱ������
�����˰׻��õĵ����ڴ��߶���
LONG);
  	set("exits",([
     		"north" : __DIR__"baistep1",
      		"south" : __DIR__"baihutang",
  	]));
  	set("no_clean_up", 0);
  	setup();
  	replace_program(ROOM);
}
