#include <ansi.h>
inherit ROOM;

string look_shibei();

void create()
{
      set("short","������");
      set("long",@LONG
�����Ƕ���ɽ�������󡣴˸�λ��ţ�����£����а�����
���к�����������֮ˮ�������������¡������й�����������
��������������������˫���š���������������һ���׸ߵ�
�ں�ɫ��ʯ��Ȼͦ��������ţ�ģ���֮Ϊ��ţ��ʯ�����ű���
��һʯ��(shibei)���ɴ������ϣ������Ǻ�����ջ������·��
����������ȥ�з��¡�
LONG);
      set("outdoors", "emei");
      set("objects", ([
           CLASS_D("emei") + "/xian" : 1,
           __DIR__"npc/girldizi" : 1,
      ]));

      set("item_desc", ([
          "shibei" : (: look_shibei :),
      ]));

      set("exits", ([
          "west"  : __DIR__"bailongdong",
          "east"  : __DIR__"zhongfengsi",
          "south" : __DIR__"heilong1",
      ]));
      setup();
      replace_program(ROOM);
}

string look_shibei()
{
        return

WHT "\nʯ������һʫԻ��\n\n"
"          ����������������������������\n"
"          ��                        ��\n"
"��������������" HIC "�� Ȼ �� �� �� �� ��" NOR + WHT "  ��\n"
"          ��                        ��\n"
"��������������" HIC "�� �� �� �� �� �� ��" NOR + WHT "  ��\n"
"          ��                        ��\n"
"��������������" HIC "�� �� ˫ Ϫ һ �� ��" NOR + WHT "  ��\n"
"          ��                        ��\n"
"��������������" HIC "�� �� �� ˮ �� ţ ��" NOR + WHT "  ��\n"
"          ��                        ��\n"
"          ����������������������������\n\n"
"����ǡ�����ʮ��ʫ����רӽ�⡸˫����������ʫ��\n" NOR;
}
