inherit ROOM;

void create()
{
      set("short","���϶�");
      set("long",@LONG
���϶�ͦ�θ��ͣ���ɲ���������ʣ��羰���ա�����
��Ұ���������ɼ���ΡΡ��������Ⱥ�����У����׷�ɽ��
����ԺҲ���۵ס��ɴ����������£���������ʯ�����¹�ʮ��
�̿ɵ������¡�������һ����ǡ�
LONG);
      set("objects", ([
           CLASS_D("emei") + "/li" : 1,
           __DIR__"npc/girldizi" : 1,
      ]));
      set("outdoors", "emei");
      set("exits", ([
          "north"    : __DIR__"majiu2",
          "westup"   : __DIR__"lianhuashi",
          "eastdown" : __DIR__"shierpan4",
      ]));
      setup();
      replace_program(ROOM);
}
