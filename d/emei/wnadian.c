inherit ROOM;

void create()
{
      set("short", "������ש��");
      set("long", @LONG
�����������ֵĹ�������ש�ש���ı�Ϊ�����Σ���Ϊ
���Բ���Σ��������������������������ͭ����һ�𡣹���
����ש���ı��·�����С���ʮ�ģ��ڸ�����������һ����
���Ϸ����к�������������ͭ��С���������߸���
LONG);
      set("objects", ([
           CLASS_D("emei") + "/kong" : 1,
           CLASS_D("emei") + "/wenfang" : 1,
      ]));
      set("exits", ([
          "east"    : __DIR__"wnachanfang",
          "out"     : __DIR__"wannianan",
      ]));
      setup();
      replace_program(ROOM);
}
