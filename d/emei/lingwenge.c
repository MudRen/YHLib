inherit ROOM;

void create()
{
      set("short", "���ĸ�");
      set("long", @LONG
�����Ǹ����ֵ����ĸ������־���ʦ̫���ڷ𷨵ĵط���
��������С����������ԣ��ƺ�������ʦ̫�Ľ̻ޡ����ڲ��ü�
ª����ǽ���ż������Σ����Ϸ��ż������š�������һ��������
����һ��ի����
LONG);
      set("objects", ([
           CLASS_D("emei") + "/zhao" : 1,
      ]));
      set("exits", ([
          "out"  : __DIR__"fushouan",
          "east" : __DIR__"fsachanfang",
          "west" : __DIR__"fsazhaitang",
      ]));
      setup();
      replace_program(ROOM);
}
