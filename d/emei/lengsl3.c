inherit ROOM;

void create()
{
      set("short", "��ɼ��");
      set("long", @LONG
����Ƭ������յ���ɼ�֡�����Ҳ�ϱ�����������ɼ����
��һ�飬֦��Ҷï����һ�����ɡ��������գ��������ڵ�˿
��Ҳ�ޡ������Ϻ��Ŀ�֦��Ҷ����Ȼ�οͺ���̤��˴���
LONG);
      set("exits", ([
          "west"      : __DIR__"bashisipan2",
          "northeast" : __DIR__"lengsl2",
          "southup"   : __DIR__"lengsl4",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
