inherit ROOM;

void create ()
{
  	set ("short","����");
  	set ("long", @LONG
�˴��ǿ��ⱱ���������뿪��ܽ����ΰ�����ȶ����ɴ�
ȥ��ɽ����Ŀ������ﲻ����һ��̫ƽ����
LONG);
  	set("outdoors", "kaifeng");
  	set("exits", ([
  		"south" : __DIR__"xuandemen",
  		"westup" : __DIR__"shanlu1",
	]));
  	setup();
        replace_program(ROOM);
}
