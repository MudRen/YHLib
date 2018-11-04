// team command: with
// modify by rcwiz

#include <ansi.h>

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;
        object* t; // ������Ա����
        object leader; // ���
        int tn; // ��������
        
	if (! arg ||
            ! (ob = present(arg, environment(me))) ||
	    ! living(ob) ||
	    ! ob->is_character() ||
	    ob == me)
		return notify_fail("�����˭��Ϊ��飿\n");

	if (! pointerp(me->query_team()) || me->is_team_leader())
        {             
                if (sizeof(me->query_team()) >= 18)   // �������ʮ���޺���
                        return notify_fail("����������������ʵ����̫��"
                                           "�ˣ���Ҷ��չ˲������ˡ�\n");

		if (me == ob->query_temp("pending/team"))
                {
			if (! pointerp(me->query_team()))
                        {
				ob->add_team_member(me);
				message_vision(HIC "$N" HIC "��������$n�Ķ��顣\n" NOR, me, ob);

                                // ��ĳ�˼�������������ж����ػ����̼��Ӷ���״��
                                // ����֣��������Ա�뿪������ڷ��䡢���ԣ�������
                                // ���ߡ����������뿪����Ȳ��ܱ��ֶ������������
                                // ��ö�Ա�����ڸö��飬��ˢ�¶����б���������
                                // ����Ч�����뿪������Ա����Ч����
                                remove_call_out("team_tray");                              
                                leader = ob;
                                t = leader->query_team();
                                tn = sizeof(t);
                                // ���봫�ݲ���Ϊtn - 1����Ϊ�����ػ����̺�Ҫ�ȵ�ˢ�µ�ʱ��Ÿ���
                                // �ö�Ա�������������幥��Ч��
                                call_out("team_tray", 1, leader, t, tn - 1); // ˢ�¶����ػ�����
			} else
                        {
				me->add_team_member(ob);
				message_vision(HIC "$N" HIC "������$n������顣\n" NOR, me, ob);

                                // ��ĳ�˼��������������ػ����̼��Ӷ���״��
                                // ����֣��������Ա�뿪������ڷ��䡢���ԣ�������
                                // ���ߡ����������뿪����Ȳ��ܱ��ֶ������������
                                // ��ö�Ա�����ڸö��飬��ˢ�¶����б���������
                                // ����Ч�����뿪������Ա����Ч����
                                leader = me;
                                remove_call_out("team_tray");
                                t = leader->query_team();
                                tn = sizeof(t);
                                // ���봫�ݲ���Ϊtn - 1����Ϊ�����ػ����̺�Ҫ�ȵ�ˢ�µ�ʱ��Ÿ���
                                // �ö�Ա�������������幥��Ч��
                                call_out("team_tray", 1, leader, t, tn - 1); // ˢ�¶����ػ�����

			}
			ob->delete_temp("pending/team");
			return 1;
		} else
                {
			message_vision(HIM "$N" HIM "����$n" HIM "����$P�Ķ��顣\n" NOR, me, ob);
			tell_object(ob, NOR + YEL "�����Ը����룬���� team with " +
                                    me->query("id") + "��\n" NOR);
			me->set_temp("pending/team", ob);
			return 1;
		}
	} else
		return notify_fail("ֻ�ж����������������˼��롣\n");
}

// �����ػ�����
// ÿ�κ�����ˢ�����幥��Ч������Ա�б�
void team_tray(object leader, object* t, int tn)
{
       int i, flag, j, n_ran;
       object tob, target;

       // ���볣���飨������״����
       // ���ȼ�����״�����Ƿ���Ȼ���ڣ�
       if ( ! objectp(leader) || ! interactive(leader) || ! living(leader) )
       {                
	    message("team", HIR "������Ự��������������ε��������ߣ������"
                            "ɢ��\n" NOR, t);
               
            if (objectp(leader))
            {
                  leader->dismiss_team();
                  flag = 0;
            }
            else 
                  flag = 1;
            
            // �������幥��Ч��
            for (i = flag; i < tn; i++)
            {
                   if (objectp(t[i]) && t[i]->query_temp("add_power/team"))
                   {                   
                       t[i]->add_temp("apply/attack", -(tn * 16));
                       t[i]->add_temp("apply/armor", -(tn * 18));
	               t[i]->add_temp("apply/parry", -(tn * 10));
	               t[i]->add_temp("apply/dodge", -(tn * 8));
                       t[i]->delete_temp("add_power/team");
                       t[i]->dismiss_team();
                   }
                 
            }
            return;
       }

       // ���м����������ԣ��Ƿ��Ѿ���ɢ��
       if (! sizeof(leader->query_team())) // �����ѽ�ɢ����������������
       {
            for (i = 0; i < tn; i++)
            {
                   if (objectp(t[i]) && t[i]->query_temp("add_power/team"))
                   {                   
                       t[i]->add_temp("apply/attack", -(tn * 16));
                       t[i]->add_temp("apply/armor", -(tn * 18));
	               t[i]->add_temp("apply/parry", -(tn * 10));
	               t[i]->add_temp("apply/dodge", -(tn * 8));
                       t[i]->delete_temp("add_power/team");
                   }
                 
            }
            return;
        }
             
       // Ȼ����������Ա�Ƿ�Ӱ�����������״��
       for (i = 1; i < tn; i ++)
       {
            if (! objectp(t[i]))continue; // �ö�Ա����

            if (  ! pointerp(t[i]->query_team()) // �ö�Ա�Ѿ��뿪����
               || environment(leader) != environment(t[i]) // �ö�Ա����Ӳ���ͬһ����               
               || ! living(t[i]) ) // �ö�Ա���Ի�������
            {   
                  // ����Ƕ�Աǿ������ӣ�ֻɾ������˹���Ч��
                  // ������Ա��Ч��ͨ������ˢ�������
                  if (  pointerp(t[i]->query_team()) 
                     && ! t[i]->is_team_leader())
                  {
                            t[i]->dismiss_team();
                            t[i]->add_temp("apply/attack", -(tn * 16));
                            t[i]->add_temp("apply/armor", -(tn * 18));
	                    t[i]->add_temp("apply/parry", -(tn * 10));
	                    t[i]->add_temp("apply/dodge", -(tn * 8));
                            t[i]->delete_temp("add_power/team");
                  }
                  else // ���Ƕ�Աͬ�����ɾ���乥��Ч��
                  {
                            t[i]->add_temp("apply/attack", -(tn * 16));
                            t[i]->add_temp("apply/armor", -(tn * 18));
	                    t[i]->add_temp("apply/parry", -(tn * 10));
	                    t[i]->add_temp("apply/dodge", -(tn * 8));
                            t[i]->delete_temp("add_power/team");
                  }
             }

      } // ���������Ա���

      // ˢ���������飡ΪʲôҪˢ�£�������鲻���Ѿ�������
      // ������Ϊ��;���п�����ʱ�����µĶ�Ա������ˢ�£�
      // ���������쳣�����Ҫͨ��ˢ��������

      // ��ɾ�����幥��Ч��      
      for (i = 0; i < tn; i++)
      {                        
             if (objectp(t[i]) && t[i]->query_temp("add_power/team"))
             {                   
                    t[i]->add_temp("apply/attack", -(tn * 16));
                    t[i]->add_temp("apply/armor", -(tn * 18));
                    t[i]->add_temp("apply/parry", -(tn * 10));
	            t[i]->add_temp("apply/dodge", -(tn * 8));
                    t[i]->delete_temp("add_power/team");
              }                 
       }

      // ��ȡ�µĶ�Ա�б������ȡһ�Σ��������¶�Ա����
      t = leader->query_team();
      t -= ({ 0 });
      tn = sizeof(t); // ���tn��������Ч����Ч���

      // �������߻����������Ա����Ϊ��Щ����䲻����һ�����
      // ���ֱ�����ûᵼ�³������Ҹ����ص��Ǵ��󲻻�����ʾ
      // �䵼�¶����ػ�������ֹ�����Ա������ objectp(ob)����
      // �жϣ�������������ֱ�����á�
      // ͨ�����ѭ�������˵�������������Ч���������Ա��
      j = 0;
      for (i = 0; i < tn; i++)
      {
              if (! objectp(t[i]))continue;
              j += 1;

      }

      tn = j;
 
      // ���ֻʣ���һ�˵�ʱ������ɢ
      // ������������ˢ�µ�ʱ����ã���Ϊ���������ǰ��Ļ�
      // ����һ����ӵ�ʱ��ϵͳ������Ϊ������ֻ�����һ�ˣ�Ȼ��
      // ���������˼��롣���Է���ǰ��ͻᵼ����Զ�޷��齨����

      if (tn <= 1)leader->dismiss_team();

      // �����ɢ�󱾴β����������������´ε��ö����ػ����̵�ʱ������

      // ˢ�����幥��Ч��
      for (i = 0; i < tn; i++)
      {        
               if (! objectp(t[i]))continue;
               t[i]->add_temp("apply/attack", tn * 16);
               t[i]->add_temp("apply/armor", tn * 18);
               t[i]->add_temp("apply/parry", tn * 10);
	       t[i]->add_temp("apply/dodge", tn * 8);
               t[i]->set_temp("add_power/team", 1);
         
      } // ˢ�����幥��Ч�����


  /*  
      ///////////////////////////////////////////////////////////////////////////////////////
      // ÿ����һ�ζ����ػ����̱����һ���ж�
      // ���ж�Ϊ���Ӷ�����������⹥��Ч��
      // �������busy��͵Ϯ���Լ����ĶԷ��ľ������������ˣ��ȡ�
      // ���Ϊ�󷨸���Ч�������ǿ�������и���Ĺ���Ч���ͷ���Ч��
      n_ran = 0;
      if (tn > 1) // ��֤����û�н�ɢ�Ż�������Ч��
      {    
           // ��ȡ���busy����
           switch (tn) // ������busy����Ϊ��ͨ���飨���󷨣��ġ��󷨵����busy�������ں���������
           {     // ���ڸ��ж���һ�����һ�Σ����Ա�����ͼ���
                 case 18 : n_ran = 30;  break;
                 case 17 : n_ran = 35;  break;
                 case 16 : n_ran = 45;  break;
                 case 15 : n_ran = 61;  break;
                 case 14 : n_ran = 81;  break;
                 case 13 : n_ran = 103; break;
                 case 12 : n_ran = 130; break;
                 case 11 : n_ran = 160; break;
                 case 10 : n_ran = 195; break;
                 case 9  : n_ran = 235; break;
                 case 8  : n_ran = 283; break;
                 case 7  : n_ran = 338; break;
                 case 6  : n_ran = 350; break;
                 case 5  : n_ran = 370; break;
                 case 4  : n_ran = 392; break;
                 case 3  : n_ran = 398; break;
                 default : n_ran = 2; break;
           } // ��ȡ���busy�������
      
           // �󷨵����busy����������������
           //...........................
           //...........................
 
          // ���busyЧ����ʼִ��
          // �����ж϶����Ƿ���Ⱥ��ս�������ж����
          if (objectp(tob)target = tob->select_opponent();
          if (leader->is_fighting(target))
          {                                 
               tob = t[random(tn)]; // �����ȡһ����Ա
               // ִ������busyЧ��
               if (tob->is_fighting(target) && random(n_ran) == 1)
               {
                      message_vision(HIW "$n" HIW "ֻ��$N" HIW "����Խ��Խ�ͣ����ɵ���Ŵ��ҡ�\n" NOR,
                                     target, leader);
                      
                      if (! target->is_busy())target->start_busy(random(tn));            

               } // ����busyЧ��ִ����ϡ�

                
          }// 
          
      } // ����Ч��ִ�����

//////////////////////////////////////////////////////////       /////////       /////////    
*/
      // ���ֶ����ػ����̲�ֹͣ��ÿ��һ�����һ��
      remove_call_out("team_tray");

      // ���ʱ���tnΪ���������Ա�������������ԣ��������������ߵ���Ա      
      call_out("team_tray", 1, leader, t, tn);
             
}
