inherit ROOM;

void create()
{
  	set("short", "Ϸ����¥");
  	set("long", @LONG
���������չ����������ĵط����м�������Ů������ר��
���µ����䣬�м����ֳ��񽣣��ڻ�����У����鶯������
��������һ�㣬�㿴��Ҳ�̲�סԾԾ���ԡ�
LONG);
  	set("exits",([
      		"down" : __DIR__"liangong",
      		"up"   : __DIR__"liangong3",
  	]));
  	set("for_family", "���չ�");
  	setup();
  	replace_program(ROOM);
}
