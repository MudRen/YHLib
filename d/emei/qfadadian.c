inherit ROOM;

void create()
{
      set("short", "���");
      set("long", @LONG
ǧ�����ڵ���߹���������ׯ�ϡ�������һ������ǧ��
���ƣ��������������ڵ��壬���з��������������У����ƾ�
���ޱȡ�
LONG);
      set("objects", ([
           CLASS_D("emei") + "/hui" : 1,
           CLASS_D("emei") + "/wenyin" : 1,
      ]));
      set("exits", ([
          "out"  : __DIR__"qianfoan",
          "east" : __DIR__"qfachanfang",
      ]));
      setup();
      replace_program(ROOM);
}
